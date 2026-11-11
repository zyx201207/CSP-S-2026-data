#include<bits/stdc++.h>
using namespace std;
int n,l,r,x[200010];
long long sum;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>c[i];
	r=n-1;
	while(l!=r){
		if(c[l]!=c[r])
			sum+=min(x[l],x[r]);
		if(x[l]>x[r]){
			x[l]-=x[r];
			r--;
		}
		else{
			x[r]-=x[l];
			l++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
