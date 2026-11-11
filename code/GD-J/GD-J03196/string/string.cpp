#include<bits/stdc++.h>
using namespace std;
int n,num_left,num_right;
const int N=5e5+10;
long long int len[N];
long long ans;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i]>>a[i];
		
	}	
	for(int l=1,r=n;;){
		if(num_left==0)num_left=len[l];
		if(num_right==0)num_right=len[r];
		if(a[l]!=a[r]){
			ans+=min(num_left,num_right);
			//cout<<l<<' '<<r<<' '<<ans<<' ';	
		}
		if(num_left<num_right){
			num_right-=num_left;
			num_left=0;
			l++;
			if(num_right==0)r--;
		}
		else {
			num_left-=num_right;
			num_right=0;
			r--;
			if(num_left==0)l++;
				
		}
		
		if(l>=r)break; 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//coder by:chen 
