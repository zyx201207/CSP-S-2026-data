#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005];
int n,m;
void pai(int c){
	int b[500005];
	for(int i=1;i<=n;i++){
		b[i]=a[i+c-1];
	}
	for(int i=2;i<=n-c+1;i++){
		for(int j=1;j<=i;j++){
			if(b[i]==b[j]){
				for(int k=j;k<i;k++){
					b[k]=0;
				}
			}
		}
	}
	for(int i=1;i<=n-c+1;i++){
		for(int j=1;j<=m;j++){
			if(b[i]==j){
				cnt[j]++;
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		pai(i);
	}
	cnt[m]++;
	for(int i=1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
