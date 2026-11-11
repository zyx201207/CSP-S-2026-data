//GZ-J00462 遵义市第十一中学 祝家懿 
#include<bits/stdc++.h>
using namespace std;
struct cc{
	long long a;
	char b;
};
cc s[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a;
		cin>>s[i].b;
	} 
	int wz=n-1,i=0;
	long long ans=0;
	for(int p=0;;p++){
		if(s[i].b!=s[wz].b){
			if(s[i].a>s[wz].a){
				ans+=s[wz].a;
				s[i].a=s[i].a-s[wz].a;
				s[wz].a=0;
				wz--;
			}
			else{
				ans+=s[i].a;
				s[wz].a=s[wz].a-s[i].a;
				s[i].a=0;
				i++;
			}
		}
		else{
			if(s[i].a>s[wz].a){
				s[i].a=s[i].a-s[wz].a;
				s[wz].a=0;
				wz--;
			}
			else{
				s[wz].a=s[wz].a-s[i].a;
				s[i].a=0;
				i++;
			}
		}
		
		if(i>=wz){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
