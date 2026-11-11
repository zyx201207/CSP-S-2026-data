#include <bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
long long a[mxn];
char c[mxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	pair<long long,char>pre;
	pre.first=0;
	bool end=false;//前面还是后面 
	int f=1,e=n;
	for(int i=1;i<=n;i++){
		if(e<=f) break;
		if(pre.first){
			if(end){
				if(a[e]<pre.first){
					if(c[e]!=pre.second) ans+=a[e];
					c[e]=pre.second;
					pre.first-=a[e];
					//a[n-i+1]=0;
					e--;
				//	cout<<"(debugec:"<<pre.first<<" "<<pre.second<<" "<<e<<" "<<f<<")"<<endl;
					continue;//传给下一个元素 
				}else{
				//	cout<<"dd:"<<a[e]<<" "<<c[e]<<" "<<a[f]<<" "<<c[f]<<endl;
					a[e]-=pre.first;
					ans+=pre.first;
					pre.first=0;
				//	cout<<"(debuge:"<<pre.first<<" "<<pre.second<<" "<<e<<" "<<f<<" "<<ans<<")"<<endl;
					f++;
				}
			}else{
				if(a[f]<pre.first){
					if(c[f]!=pre.second) ans+=a[f];
					c[f]=pre.second;
					pre.first-=a[f];
					//a[n-i+1]=0;
					f++;
				//	cout<<"(debugfc:"<<pre.first<<" "<<pre.second<<" "<<e<<" "<<f<<")"<<endl;
					continue;
				}else{
					a[f]-=pre.first;
					ans+=pre.first;
					pre.first=0;
				//	cout<<"(debugf:"<<pre.first<<" "<<pre.second<<" "<<e<<" "<<f<<")"<<endl;
					e--;
				}
			}
		}
		if(e<=f) break;
		if(a[f]>a[e]){//修改后面
			//cout<<"E"<<endl;
			//cout<<f<<" "<<e<<":"<<endl; 
			if(c[f]!=c[e]){
				ans+=a[e];
				pre.second=c[f];
				//cout<<"["<<pre.second<<"  "<<a[f]<<"]";
				pre.first+=a[f]-a[e];
				c[e]=c[f];
				//a[e]=0;
				//e--;
			}else{
				pre.second=c[f];
				pre.first+=a[f]-a[e];//剩余部分 
			}
			//cout<<pre.first<<" "<<pre.second<<"("<<"debug:"<<c[f]<<" "<<c[e]<<" "<<ans<<")"<<endl;
			e--;
			end=true;
		}else{//修改前面 
		//	cout<<"F:"<<endl;
		//	cout<<f<<" "<<e<<":"<<endl; 
			if(c[f]!=c[e]){
				ans+=a[f];
				pre.second=c[e];
				pre.first+=a[e]-a[f];
				c[f]=c[e];
				//a[f]=0;
			}else{
				pre.second=c[f];
				pre.first+=a[e]-a[f];
			}
			//cout<<pre.first<<" "<<pre.second<<"("<<"debug:"<<c[f]<<" "<<c[e]<<" "<<ans<<")"<<endl;
			f++;
			end=false;
		}
	}
	cout<<ans;
	return 0;
}
//8556378161
