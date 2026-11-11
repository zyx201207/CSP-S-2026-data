#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<long long> a(n+1,0);
	vector<char> c(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}  
	long long ans=0;
	for(int i=1,j=n;i<=n;){
		if(j<=i){
			break;
		}
		if(c[i]==c[j]){
			if(a[i]==a[j]){
				i++;
				j--;
				continue;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			ans+=min(a[i],a[j]);
			//cout<<a[i]<<" "<<c[i]<<" "<<a[j]<<" "<<c[j]<<" "<<ans<<endl; 
			if(a[i]==a[j]){
				i++;
				j--;
				continue;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}//cout<<1;
	}
	cout<<ans;
	return 0;
}
/*
3 
2 a
2 b
1 c


2 
2 a
3 a


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
