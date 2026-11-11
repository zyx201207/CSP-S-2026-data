#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],al[200005],ar[200005],l,r,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		al[i]=al[i-1]+1;
		ar[i]=al[i]+a[i]-1;
	}
	r=ar[n],l=1;
	int j=n,i=1;
	while(r>l&&i<j){
		if(c[j]==c[i]){
			if(ar[i]-l<r-al[j]){
				r-=ar[i]-l+1;
				l=al[i+1];
				i++;
			}else if(ar[i]-l>r-al[j]){
				l+=r-al[j]+1;
				r=ar[j-1];
				j--;
			}else{
				r=ar[j-1];
				l=al[i+1];
				i++,j--;
			}
		}else{
			if(ar[i]-l<r-al[j]){
				ans+=ar[i]-l+1;
				r-=ar[i]-l+1;
				l=al[i+1];
				i++;
			}else if(ar[i]-l>r-al[j]){
				ans+=r-al[j]+1;
				l+=r-al[j]+1;
				r=ar[j-1];
				j--;
				
			}else{
				ans+=r-al[j]+1;
				r=ar[j-1];
				l=al[i+1];
				i++,j--;
				
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
