#include<bits/stdc++.h>
using namespace std;
long long n,a[300005],cnt=0,sum=0,l=1,r,mid,ll,rr;
string s;
char ch[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>ch[i];
	}
	mid=sum/2,r=n,rr=sum;
	while(l!=r){
		if(a[l]<=a[r]){
			if(ch[l]!=ch[r]){
				cnt+=a[l];
			}
			ll+=a[l],rr-=a[l];
			a[r]-=a[l];l++;
		}else{
			if(ch[l]!=ch[r]){
				cnt+=a[r];
			}
			ll+=a[r],rr-=a[r];
			a[l]-=a[r];r--;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
