#include<bits/stdc++.h>
using namespace std;
struct in{
	long long k;
	char a;
}s[10000006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].k>>s[i].a;
	}
	int i=1,j=n;
	while(i<j){
		if(s[i].a==s[j].a){
			if(s[i].k>s[j].k){
				s[i].k-=s[j].k;
				j--;		
				}
				else{
					if(s[i].k==s[j].k){
						i++;
						j++;
					}
					else{
						s[j].k-=s[i].k;
						i++;
					}
				}
				
		}
		else{
			if(s[i].k>s[j].k){
				s[i].k-=s[j].k;
				cnt+=s[j].k;
				j--;		
				}
				else{
					if(s[i].k==s[j].k){
						cnt+=s[i].k;
						i++;
						j++;
					}
					else{
						s[j].k-=s[i].k;
						cnt+=s[i].k;
						i++;
					}
				}
		} 
	}
	cout<<cnt;
	return 0;
}
