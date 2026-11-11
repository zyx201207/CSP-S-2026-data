#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int sum[M];
//队列忘了  qwq    
int n, m;
struct qu{
	int last, next;
	int number;	
	bool out=false;
} a[N];
qu b[N];
//qu c[N];
int now=1;

void copys() {
	for (int i=1;i<=n;i++) {
		b[i].number=a[i].number;
		b[i].out=false;
	}
}

//void copyc(){
//	for (int i=0;i<=n;i++){
//		c[i].number=0;
//		c[i].last=-1;
//		c[i].next=-1;
//		c[i].out=false;
//	}
//}

bool findn(int zx){
	for (int i=1;i<=n;i++){
		if (!b[i].out and b[i].number==zx) return false;
	}
	return true;
}

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout)
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i].number;
	
	copys();
//	copyc();
	
	for(int i=1;i<=n;i++){
		b[0].number=0;
		b[0].last=-1;
		if (findn(b[i].number)){
			cout << "放入" << b[i].number << endl;
			b[now-1].next=i;
			b[i].last=now++;
		}else{
			cout << "扔掉" << b[i].number << endl;
			for (int j=1;j<=n;j++){
				if (b[i].number==b[j].number){
					b[i].last=0;
					b[j].out=true;
					while (b[now-1].last==-1){
						now--;
						cout << "扔掉" << b[now].number << endl;
						b[now].out=true;
					}
					break;
				}
			}
		}
		for (int mn=1;mn<=m;mn++){
			for (int j=1;j<=n;j++){
				if (!b[j].out and b[j].number==mn){
					sum[mn]++;
				}
			}
		}
		copys();
	}
	for (int i=1;i<=m;i++){
		cout << sum[i] << ' ';
	}
	return 0;
}
