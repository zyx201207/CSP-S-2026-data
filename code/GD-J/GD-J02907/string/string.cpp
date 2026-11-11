#include<bits/stdc++.h>
using namespace std;
struct duan{
	int a;
	char b;
}b[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i].a>>b[i].b;
	}
	for(int i=0,j=n-1;i<j;){
		if(b[i].b!=b[j].b){
			ans+=min(b[i].a,b[j].a);
		}
		if(b[i].a==b[j].a)i++,j--;
		else if(b[i].a<b[j].a)b[j].a-=b[i].a,i++;
		else b[i].a-=b[j].a,j--;
	}
	cout<<ans;
} 
