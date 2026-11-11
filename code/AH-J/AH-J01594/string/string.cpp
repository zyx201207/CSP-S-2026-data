#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l,lx,ly,ans,sum,f=1,t=1;
char c[200005];
struct no{
	int x;
	char c;
}x[2000005],y[2000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)l+=a[i];
	l/=2;
	for(int i=1;i<=n;i++){
		if(sum<l&&sum+a[i]>l){
			x[++lx].x=l-sum;
			x[lx].c=c[i];
			break;
		}
		x[++lx].x=a[i];
		x[lx].c=c[i];
		sum+=a[i];
		if(sum==l)break;
	}
	sum=0;
	for(int i=n;i>=1;i--){
		if(sum<l&&sum+a[i]>l){
			y[++ly].x=l-sum;
			y[ly].c=c[i];
			break;
		}
		y[++ly].x=a[i];
		y[ly].c=c[i];
		sum+=a[i];
		if(sum==l)break;
	}
//	cout<<endl; 
//	for(int i=1;i<=lx;i++)cout<<x[i].x<<" "<<x[i].c<<endl;
//	cout<<endl;
//	for(int i=1;i<=ly;i++)cout<<y[i].x<<" "<<y[i].c<<endl;
	while(f<=lx&&t<=ly){
//		cout<<"f:"<<f<<" "<<x[f].x<<" "<<x[f].c<<endl;
//		cout<<"t:"<<t<<" "<<y[t].x<<" "<<y[t].c<<endl;
//		cout<<endl;
		if(x[f].c!=y[t].c){
			if(x[f].x>y[t].x){
				ans+=y[t].x; 
				x[f].x-=y[t].x;
				t++;
			}else if(x[f].x<y[t].x){
				ans+=x[f].x; 
				y[t].x-=x[f].x;
				f++;
			}else{
				ans+=x[f].x; 
				f++,t++;
			}
		}else{
			if(x[f].x>y[t].x){
				x[f].x-=y[t].x;
				t++;
			}else if(x[f].x<y[t].x){
				y[t].x-=x[f].x;
				f++;
			}else{
				f++,t++;
			}
		}
	}
	cout<<ans;
	return 0;
}

