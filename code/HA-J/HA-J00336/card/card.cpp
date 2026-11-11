#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[300005],shu[300005],a[500005],vis[500005];
stack<int>moni;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
    	cin>>a[i];
    	vis[a[i]]++;
    }

    for(int i=n;i>=1;--i){
        for(int j=n-i+1;j<=n;++j){
    
        	shu[a[j]]++;
        	if(shu[a[j]]>1){
    
        		while(moni.top()!=a[j]){
        			int w=moni.top();
        			shu[w]--;
 
        			moni.pop();
        		}
        		//cout<<endl;
        		continue;
        	}
        
        	moni.push(a[j]);
        }
        for(int q=1;q<=n;++q){
        	if(shu[q]!=0)cnt[q]++;
        	shu[q]=0;
        }
        while(!moni.empty()){
        //	cout<<moni.top();
        	moni.pop();
        }
       // cout<<endl;
    }
    for(int i=1;i<=n;++i){
    	if(vis[i]==0)continue;
    	cout<<cnt[i]<<" ";
    }
	return 0;
	
}



