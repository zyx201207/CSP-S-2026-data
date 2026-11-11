#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int ans[10000005];
struct id{
	int p;
};
id b[100005];
int num[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    int left=1;
    int right=1;
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		if(num[a[j]]==0){
    			num[a[j]]++;
    			b[right++].p=a[j];
    			
			}
			else{
				int v;
				num[a[j]]=0;
				for(int d=left;d<=right;d++){
					if(b[d].p==a[j]){
						v=d+1;
						break;
					}
				}
				int v2=v;
				while(v<=right){
					num[b[v].p]--;
					b[v].p=0;
					v++;
				}	
				right=v2;
				num[a[j]]++;
				b[right].p=a[j];
			}
		}
		for(int j=i;j<=n;j++){
			if(num[a[j]]!=0){
				ans[a[j]]++;
			}
			num[a[j]]=0;
			
		}
		for(int j=left;j<=right;j++){
			b[a[j]].p=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]!=0)
			cout<<i<<" ";
	}
    return 0;
}
