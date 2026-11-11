#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct data{
	char c;
	int a;
}d[200005];
stack<data> p;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0,res=0;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].c;
		sum+=d[i].a;
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		if((res+d[i].a)>(sum/2)){
			p.push({d[i].c,sum/2-res});
			d[i].a-=(sum/2-res);
			if(sum%2==1)d[i].a--;
			pos=i;
			break;
		}else{
			res+=d[i].a;
			p.push({d[i].c,d[i].a});
		}
	}
	for(int i=pos;i<=n&&(!p.empty());){
		data tem=p.top();
		if(d[i].a>tem.a){
			if(d[i].c==tem.c){
				d[i].a-=tem.a;
			}else{
				ans+=tem.a;
				d[i].a-=tem.a;
			}
			p.pop();
		}else if(d[i].a==tem.a){
			if(d[i].c==tem.c){
				i++;
			}else{
				ans+=tem.a;
				i++;
			}
			p.pop();
		}else{
			if(d[i].c==tem.c){
				p.top().a-=d[i].a;
				i++;
			}else{
				ans+=d[i].a;
				p.top().a-=d[i].a;
				i++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
