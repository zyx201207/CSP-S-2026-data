#include<bits/stdc++.h>
using namespace std;
struct sd{
	long long nu;
	char z;
};
sd s[200005];
long long n,l,r;
unsigned long long cnt=0; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//delete_the_freopen
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].nu>>s[i].z;
	}
	l=0;
	r=n-1;
	while(l<=r){
		if(s[l].z==s[r].z){
			if(s[l].nu>s[r].nu){
				s[l].nu-=s[r].nu;
				r--;
			}
			else if(s[l].nu<s[r].nu){
				s[r].nu-=s[l].nu;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(s[l].nu>s[r].nu){
				s[l].nu-=s[r].nu;
				cnt+=s[r].nu;
				r--;
			}
			else if(s[l].nu<s[r].nu){
				s[r].nu-=s[l].nu;
				cnt+=s[l].nu;
				l++;
			}
			else{
				cnt+=s[r].nu;
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
}
