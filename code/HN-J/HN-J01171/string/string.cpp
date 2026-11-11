#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	int num,q=1,cut=0;
	long long a[100003],h=0;
	char c[100003];
	string s;
	cin>>num; 
	if(num==1){
		cin>>a[1]>>c[1];
		cout<<0;return 0;
	}else{
		for(int i=1;i<=num;i++){
			cin>>a[i]>>c[i]; 
			h+=a[i];
			if(i>=2&&q==1&&c[i]!=c[i-1]){
				q=0;
			} 
		}
		if(q==1){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=num;i++){
				for(int j=1;j<=a[i];j++){
					s+=c[i]; 
				} 
		}
		if(h%2==1){
			for(int i=1;i<=(h-1)/2;i++){
				if(s[i]!=s[h+1-i]){
					cut=cut+1;
				} 
			}
			cout<<cut;
		} else{
			for(int i=1;i<=h/2;i++){
				if(s[i]!=s[h+1-i]){
					cut=cut+1;
				} 
			}
			cout<<cut;
		}
	}
	return 0;
}  
