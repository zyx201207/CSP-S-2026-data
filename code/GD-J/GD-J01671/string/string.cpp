#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char b;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	int r=1,l=n;
	long long sum=0;
	while(r<l){
		while(s[r].a>=s[l].a&&s[r].a!=0){
			s[r].a-=s[l].a;
			if(s[r].b!=s[l].b){
				sum+=s[l].a;
			}
			l--;
		}
		while(s[r].a<s[l].a){
			s[l].a-=s[r].a;
			if(s[r].b!=s[l].b){
				sum+=s[r].a;
			}
			r++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
