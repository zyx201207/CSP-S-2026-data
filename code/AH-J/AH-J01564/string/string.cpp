#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char a;
};
node c[200010],d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i].x>>c[i].a;
	long long len=0;
	for(int i=1;i<=n;i++){
		if(c[i].a==c[i-1].a){
			d[len].x+=c[i].x;
		}
		else
			d[++len]=c[i];
	}
	if(len==1){
		cout<<0;
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=len;i++){
		sum+=d[i].x;
	}
	long long r=len,ans=0,ln=0,rn=0;
	for(int i=1;i<=r;){
		if(d[i].a!=d[r].a){
			if(ln+d[i].x>=rn+d[r].x){
				ans+=min(d[i].x,d[r].x);
				//ans+=ln+d[i].x-rn-d[r].x;
				d[i].x-=d[r].x;
				r--;
			}
			else{
				ans+=min(d[i].x,d[r].x);
				d[r].x-=d[i].x;
				i++;
			}
			//ans+=min(d[i].x,d[r].x);
		}
		else{
			if(ln+d[i].x==rn+d[r].x){
				i++;
				r--;
			}
			else if(ln+d[i].x>rn+d[r].x){
				d[i].x-=d[r].x;
				r--;
			}
			else{
				d[r].x-=d[i].x;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
