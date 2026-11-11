#include<bits/stdc++.h>
using namespace std;
int n;
int m;
long long a[200010];
queue<long long> q,q1;
int cnt[100];
int yo[100];
int maxx;
int flag;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,l,j;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	while(q.size()>m){
		memset(cnt,0,sizeof(cnt));
		maxx=0;
		flag=-1;
		while(!q.empty()){
			int l=q.front();
			q1.push(l);
			int j=0;
			q.pop();
	    	while(l!=0){
		    	if(l%2==1){
		    		cnt[j]++;
		    	}
		    	l/=2;
		    	j++;
		    	maxx=max(maxx,j);
	    	}
    	}
    	maxx--;
    	for(int i=maxx;i>=0;i--){
    		if(yo[i]){
    			continue;
			}
	    	if(cnt[i]>=m){
	    		flag=i;
	    		yo[flag]=1;
	    		break;
	    	}
    	}
    	if(flag==-1){
    		while(!q1.empty()){
				q.push(q1.front());
    			q1.pop();
	    	}
    		break;
		}
		while(!q1.empty()){
			if(((q1.front()>>flag)&1)==1){
				q.push(q1.front());
			}
			q1.pop();
		}
	}
	ans=q.front();
	q.pop();
	while(!q.empty()){
		ans&=q.front();
		q.pop();
	}
	cout<<ans;
	return 0;
}
