#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
long long n,i,a[N],sum,ans,cnt;
struct a{
	long long x;
	char y;
}s[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		i++;
		cin>>s[i].x>>s[i].y;
		sum+=s[i].x;
	}
	sum/=2;
	for(int i=1;i<=n;i++){
		if(s[i].x>=sum){
			ans=i;break;
		}
	}
	long long l=1,r=n,L=0,R=0;
	
	while(l<=ans&&r>=ans){
		if(s[l].y!=s[r].y){
			if(s[l].x!=s[l].x&&l-1==n-r){
				if(s[l].x<s[r].x){
					cnt+=s[r].x-s[l].x;
					l++;
				}if(s[l].x>s[r].x){
		    		cnt+=s[l].x-s[r].x;
		    		r--;
				}else{cnt+=s[l].x;}	
			}
			if(l-1!=n-r){
				if(s[l].x>s[r].x){
					L=s[r].x;
					if(s[r].y!=s[l].y)cnt+=L;
					s[l].x-=L;
				}
	            if(s[l].x<s[r].x){
	            	R=s[L].x;
	            	if(s[r].y!=s[l].y)cnt+=R;
	            	s[r].x-=R;
				}
			}
		}
		
	}
	cout<<cnt;
	return 0;
}
