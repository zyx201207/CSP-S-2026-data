#include<bits/stdc++.h>
using namespace std;
long long n,cnt,a[200010],l,r;
char c[200010];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	r=n-1;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;	
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				cnt+=a[l];
				l++;
				r--;
			}		
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
