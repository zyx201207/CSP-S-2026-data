#include<bits/stdc++.h>
using namespace std;
int t[3005],a[500005],b[3005],an[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdin);
    int n,m,len=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int l=1;l<=n;l++){
		memset(t,0,sizeof(t));
		for(int i=l;i<=n;i++){
			if(t[a[i]]!=0){
				for(int j=t[a[i]]+1;j<=len;j++){
					t[b[j]]=0;
					b[j]=0;
				}
				len=t[a[i]];
			}else{
				len++;
				t[a[i]]=len;
				b[len]=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]!=0){
				an[i]++;
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<an[i]<<" ";
			
	}
    return 0;
}
