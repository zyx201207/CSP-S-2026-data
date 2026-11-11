#include<bits/stdc++.h>
using namespace std;
const long long M=5*1e5+10;
long long a[M],b[M],d[M],cnt,ans;
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long r=1;r<=n;r++){
		if(r==1){
			for(long long i=1;i<=n;i++){
		        cin>>b[i];
		        q.push(b[i]);
		        ans++;
		        if(a[b[i]]==0){
			        a[b[i]]=1;
		            cnt++;
		        }else{
			        for(long long j=1;j<=cnt;j++){
				        if(q.front()!=b[i]){
					        a[q.front()]=0;
				        }
				        q.pop();
				        ans--;
			        }   
		        }
		    }
		    for(long long i=1;i<=ans;i++){
		    	d[q.front()]++;
		    	q.pop();
			}
			ans=0;
		}else{
			for(long long i=r;i<=n;i++){
				q.push(b[i]);
				ans++;
		        if(a[b[i]]==0){
			        a[b[i]]=1;
		            cnt++;
		        }else{
			        for(long long j=1;j<=cnt;j++){
				        if(q.front()!=b[i]){
					        a[q.front()]=0;
				        }
				        q.pop();
				        ans--;
			        }   
		        }
		    }
		    for(long long i=1;i<=ans;i++){
		    	d[q.front()]++;
		    	q.pop();
			}
			ans=0;
			
		}
		
	}
    for(long long i=1;i<=m;i++){
	    cout<<d[i]; 
    }
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
