//GZ-J00399贵阳中天中学蒲科印 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
long long n,m,e;
long long a[N],cnt[N],b[N],ccnt[N];
bool ff=0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			e=a[j];
			bool flag=0;
			for(int k=1;k<=n;k++){
				if(b[k]==e){
					flag=1;
					for(int l=k;l<=n;l++){
						b[l]=0;
					}
					b[k]=e;
				}
			}
			if(flag==0){
				b[j]=e;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=0){
				cnt[b[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]>=1)cout<<cnt[i]<<" ";
	}
	return 0;
}


