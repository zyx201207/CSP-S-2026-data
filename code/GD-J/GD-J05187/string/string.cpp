#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string st;
ll n,s,x[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>x[i]>>c[i];	
		sum+=x[i];
	}
	ll l=0,r=n-1,sl=0,sr=0;
	char cl=' ',cr=' ';
	while(l<r){
		if(sl!=0){
			if(x[r]>=sl){
				if(c[r]!=cl and cl!=' ') s+=sl;
				sl=0;
				sr=x[r]-sl;
				if(sr!=0) cr=c[r];
			}else{
				if(c[r]!=cl and cl!=' ') s+=x[r];
				sl-=x[r];
			}
			r--;
		}
		else if(sr!=0){
			if(x[l]>=sr){
				if(c[l]!=cr and cr!=' ') s+=sr;
				sr=0;
				sl=x[l]-sr;
				if(sl!=0) cl=c[l];
			}else{
				if(c[l]!=cr and cr!=' ') s+=x[l];
				sr-=x[l];
			}
			l++;
		}
		else{
			cl=' ';
			cr=' ';
			if(c[l]!=c[r]){
				s+=min(x[l],x[r]);
				if(x[l]>x[r]){
					sl=x[l]-x[r];
					cl=c[l];
					r--;
				}
				else if(x[l]<x[r]){
					sr=x[r]-x[l];
					cr=c[r];
					l++;
				}
				else{
					l++;
					r--;
				}
			}
			else{
				if(x[l]>x[r]){
					sl=x[l]-x[r];
					cl=c[l];
					r--;
				}
				else if(x[l]<x[r]){
					sr=x[r]-x[l];
					cr=c[r];
					l++;
				}
				else{
					r--;
					l++;
				}
			}
		}
	}
	if(s>sum/2) s=sum/2;
	cout<<s;
	return 0;
}
