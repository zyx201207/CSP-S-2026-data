#include<bits/stdc++.h>
using namespace std;
long long n,mid,minn,s,ans;
struct node{
	long long a;
	char b;
};
node l[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
    	cin>>l[i].a>>l[i].b;
		s+=l[i].a;
	}
	for(int i=1;i<=n;i++){
    	
    	if(l[i].b==l[i+1].b){
    		ans++;
		}
	}
	if(ans==n-1){
		cout<<0;
		return 0;
	}
	mid=s/2;
	for(int i=1;i<n/2;i++){
    	if(l[i].b==l[n-i+1].b)mid-=abs(l[i].a-l[n-i].a);
	}
	
	cout<<min(mid,s/2);
	return 0;
}

