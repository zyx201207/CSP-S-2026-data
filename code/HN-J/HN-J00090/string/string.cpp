#include<bits/stdc++.h>
using namespace std;
long long s[200010],a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,Answer=0;
    cin>>n;
    s[0]=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	s[i]=s[i-1]+a[i-1];
	}
	long long l=1,r=s[n]+a[n],lw=1,rw=n;
	while(lw<=rw){
		if(c[lw]!=c[rw]){
			if(s[lw+1]-l<r-s[rw]){
				r-=s[lw+1]-l;
				Answer+=s[lw+1]-l;
				l=s[lw+1];
			}
			else{
				l+=r-s[rw];
				Answer+=r-s[rw];
				r=s[rw];
			}
		}
		else{
			if(s[lw+1]-l<r-s[rw]){
				r-=s[lw+1]-l;
				l=s[lw+1];
			}
			else{
				l+=r-s[rw];
				r=s[rw];
			}
		}
		while(l>=s[lw+1]){
			lw++;
		}
		while(r<=s[rw]){
			rw--;
		}
	}
	cout<<Answer;
}
