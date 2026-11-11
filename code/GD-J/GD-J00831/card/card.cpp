#include<iostream>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],l[N],lst[M],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		int tmp=i;
		l[i]=lst[a[i]];
		lst[a[i]]=i;
		while(tmp!=n+1){
			int x=l[tmp];
			if(x==0){
				cnt[a[tmp]]++;
				tmp++;
			}else{
				tmp=l[tmp];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
}
