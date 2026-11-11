#include<bits/stdc++.h>
using namespace std;
long long n,b,e,cnt[100],cnt2[100],t,cnt1,a[90000000];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		fill(a+1,a+b+1,int(c));
		cnt[int(c-'a')]++;
		cnt2[int(c-'a')]+=b;
		cnt1+=b;
	}
	for(int i=0;i<=26;i++){
		if(cnt[i]!=0){
			e++;
		}
	} 
	if(e==1){
		cout<<0;
		return 0;
	}else{
	
		if(e%2==0){
			for(int i=1;i<cnt1;i++){
				if(a[cnt1]!=a[i]){
					t++;
				}
				cnt1--;
			}
			cout<<t;
		}
		else{
			for(int i=1;i<=cnt1;i++){
				if(a[cnt1]!=a[i]){
					t++;
				}
				cnt1--;
			}
			cout<<t;
		}
	}
	cout<<endl;
	return 0;
}
