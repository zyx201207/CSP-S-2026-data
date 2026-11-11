#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
long long s=0,a[N];
string c; 
cin>>n;
for(int i=1;i<=n;i++){
	scanf("%d %c",&a[i],&c[i]);
}
if(n==1){
	cout<<0;
	return 0;
}
int l=1,r=n;
while(l<r){
	if(c[l]==c[r]){
		if(a[l]>a[r]){
		    a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
		        a[r]-=a[l];	
                l++;	
		}
		else{
			l++,r--;
		}
	}
	else if(c[l]!=c[r]){
		if(a[l]>a[r]){
		    a[l]-=a[r];
			s+=a[r];
			r--;
			
		}
		else if(a[l]<a[r]){
		        a[r]-=a[l];
			    s+=a[l];
			    l++;
			    
		}
		else {
			s+=a[l],l++,r--;
		}
	}
}
printf("%d",s);
return 0;
}

