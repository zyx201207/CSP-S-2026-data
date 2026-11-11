#include<bits/stdc++.h>
using namespace std;
int q,a[500005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long M,m;
	cin>>n>>M;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		m=M;
		for(int j=i-1;j>=0;j--){
			q=a[i]-a[j];
			m=m-q;
			if(m==0) {
				ans=ans>(i-j+1)?ans:(i-j+1);
				break;
			}
			else if(m<0) {
			ans=ans>(i-j)?ans:(i-j);
			break;}
		
		}
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
