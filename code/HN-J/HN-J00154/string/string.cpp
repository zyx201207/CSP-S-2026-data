#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long nu;
	char zm;
};
long long n,ans;
long long sum;
vector<Node> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		a.push_back({x,c});
		sum+=x;
	}
	long long i=0;
    long long x=1,y=sum; 
	n--;
	long long mid=sum/2;
	while(i<=n){
		long long v=a[i].nu;
		long long t=a[n].nu;
		if(v>t){
			x+=t;
			y-=t;
			if(a[i].zm!=a[n].zm)ans+=t;
			a[i].nu-=t;
			n--;	
		}else if(v<t){
			x+=v;
			y-=v;
			if(a[i].zm!=a[n].zm)ans+=v;
			a[n].nu-=v;
			i++;
		}else if(v==t){
			x+=t;
			y-=t;
			if(a[i].zm!=a[n].zm)ans+=v;
			i++;
			n--;
		}
	}
	cout<<ans;
	return 0; 
}
