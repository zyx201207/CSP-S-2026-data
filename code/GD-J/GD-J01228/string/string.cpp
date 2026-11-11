#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,sum,p;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum+=a[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(ch[l]!=ch[r]){
			if(a[l]<a[r])
				a[r]-=a[l],p+=a[l],l++;
			else if(a[l]>a[r])
				a[l]-=a[r],p+=a[r],r--;
			else
				p+=a[l],l++,r--;
		}
		else{
			if(a[l]<a[r])
				a[r]-=a[l],l++;
			else if(a[l]>a[r])
				a[l]-=a[r],r--;
			else
				l++,r--;
		}
	}
	cout<<p;
	return 0;
}
