#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}z[200005];
int n;
long long sum,cnt,mid,ans;
stack<node> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i].a>>z[i].c;
		mid+=z[i].a;
		q.push({z[i].a,z[i].c});
	}
	mid=(mid-1)/2;
	for(int i=1;sum<=mid;i++){
		cnt=0;
		sum+=z[i].a;
		while(z[i].a>cnt){
			node cl=q.top();
			q.pop();
			if(cl.c==z[i].c){
				if(z[i].a<cl.a){
			    	cnt+=z[i].a;
			    	q.push({cl.a-z[i].a,cl.c});
			    	if(z[i].a<=cnt)break;
				}else{
					cnt+=cl.a;
					if(z[i].a<=cnt)break;
				}
				continue;
			}
		    if(z[i].a-cnt<cl.a){
		    	cnt+=z[i].a;
		    	//cout<<2;
		    	if(z[i].a<=cnt){
		    		ans+=(cnt-z[i].a);
		    		break;
				}
				//ans+=z[i].a;
				cout<<ans<<endl;
		    	q.push({cl.a-z[i].a,cl.c});
		    	break;
			}else{
				cnt+=cl.a;
				ans+=cl.a;
				if(z[i].a<=cnt)break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
