#include<bits/stdc++.h>
using namespace std;
char c1[26];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,l=0,a,sum=0;
	char c;
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a,c2=0;
		cin>>a>>c;
		l+=a;
		c1[c-96]++;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	s1=s;
	int k=0;
	for(int i=0;i<l;i++){
		int l1=l-1;
		if(s[i]==s[l1]){
			k=1;
			l1--;
		}
		else{
			k=0;
			break;
		}
	}
	if(k){
		cout<<sum;
	}
	else{
		for(int i=0;i<26;i++){
			for(int x=0;x<l;x++){
				s1[x]=c1[i];
				sum++;
				for(int j=0;j<l;j++){
					int l1=l;
					if(s[j]==s[l1]){
						k=1;
						l1--;
					}
					else{
						k=0;
						break;
					}
				}
				if(k){
					break;
				}
			}
			s1=s;
			sum=0;
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
