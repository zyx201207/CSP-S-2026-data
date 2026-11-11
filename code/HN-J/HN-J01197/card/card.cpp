#include<iostream>
using namespace std;
long long n,m,a[500010],l[300010][2],zm[500010];
void it(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
bool pd(long long p,long long x){
	for(int i=1;i<=x;i++){
		if(zm[p]==l[x][0]){
			return (1==0);
		}
	}
	return (1==1);
}
bool h(long long x,long long k){
	for(int i=1;i<=x;i++){
		if(l[i][0]==a[k]){
			return (1==1);
		}
	}
	return (1==0);
}
bool hn(long long o,long long k){
	for(int i=1;i<=o;i++){
		if(zm[i]==a[k]){
			return (1==1);
		}
	}
	return (1==0);
}
void qk(long long o){
	for(int i=1;i<=o;i++){
		zm[i]=0;
	}
}
void cs(long long o,long long x){
	for(int i=1;i<=o;i++){
		if(pd(i,x)){
			l[zm[i]][1]++;
		}
	}
}
void w(){
	int x=1,o=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]&&h(x,i)){
				l[x][0]=a[i];
				x++;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			zm[o]=a[j];
			if(hn(o,j)){
				qk(o);
				o=0;
			}
			o++;
		}
		cs(o,x);
	}
	for(int i=1;i<=m;i++){
		cout<<l[i][1]<<" ";
	}
}
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	it();
	w();
	return 0;
} 
