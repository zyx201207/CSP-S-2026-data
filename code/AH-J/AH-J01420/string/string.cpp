#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long sum;
int a[2000001];
char ch[2000001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	for(l=0,r=n;l<=r;l++,r--){
		if(ch[l]!=ch[r]&&a[l]<a[r]){
			sum+=a[l];
			a[r]-=a[l];
			r++;
		}	
		else if(ch[l]!=ch[r]&&a[r]<a[l]){
			sum+=a[r];
			a[l]-=a[r];
			l--;
		}	
		else if(ch[l]!=ch[r]&&a[r]==a[l]){
			sum+=a[l];
		}	
		else if(a[l]<a[r]){
			a[r]-=a[l];
			r++;
		}	
		else if(a[r]<a[l]){
			a[l]-=a[r];
			l--;
		}	
		if(l==r&&n%2==1&&a[n/2]==0&&a[n/2+2]==0){
				break;
		}	
	}	
	cout<<sum;
	return 0;
}
