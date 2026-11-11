#include <bits/stdc++.h>
using namespace std;
string s;
int n,q[200003];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		char c;
		cin>>q[i]>>c;
		s+=c;
	}
	for(int i=0,j=n-1;i<=j;){
		if(s[i]!=s[j]){
			if(q[i]>q[j]){
				ans+=q[i]-q[j];
				q[i]-=q[j];
				j--;
			}else if(q[i]<q[j]){
				ans+=q[j]-q[i];
				q[j]-=q[i];
				i++;
			}else{
				ans+=q[i];
				i++;
				j--;
			}
		}else if(i!=j){
			if(q[i]>q[j]){
				q[i]-=q[j];
				j--;
			}else if(q[i]<q[j]){
				q[j]-=q[i];
				i++;
			}else{
				i++;
				j--;
			}
		}else{
			ans+=q[i]%2;
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
