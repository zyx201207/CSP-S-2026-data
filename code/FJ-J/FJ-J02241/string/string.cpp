#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int a;
	char c;
}v1[200005],v2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>v1[i].a>>v1[i].c;
		v2[n-i+1].a=v1[i].a;
		v2[n-i+1].c=v1[i].c;
		ma=max(ma,v1[i].a);
	}
	if(n<=2000&&ma<=50){
		string s="";
		string s2="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=v1[i].a;j++){
				s+=v1[i].c;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=v1[i].a;j++){
				s2+=v1[i].c;
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans/2<<endl;
		return 0;
	}else if(ma<=500){
		string s="";
		string s2="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=v1[i].a;j++){
				s+=v1[i].c;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=v1[i].a;j++){
				s2+=v1[i].c;
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans/2<<endl;
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(v1[i].a==v2[i].a&&v1[i].c==v2[i].c) continue;
		if(v1[i].a==v2[i].a){
			ans+=0ll+v1[i].a;
		}else if(v1[i].c==v2[i].c){
			if(v1[i].a<v2[i].a){
				int j=i+1,cnt2=0;
				while(j<=n/2+((n%2==1)?1:0)&&v1[i].a!=v2[i].a){
					if(v1[i].a+v1[j].a>v2[i].a){
						v1[j].a-=(v2[i].a-v1[i].a);
						cnt2+=(v2[i].a-v1[i].a);
						if(v1[j].c==v1[i].c){
							cnt2-=(v2[i].a-v1[i].a);
						}
						v1[i].a=v2[i].a;
					}else{
						v1[i].a+=v1[j].a;
						cnt2+=v1[j].a;
						if(v1[j].c==v1[i].c){
							cnt2-=v1[j].a;
						}
						v1[j].a=0;
					}
					j++;
				}
				if(v1[i].a!=v2[i].a){
					ans+=0ll+cnt2;
					break;
				}else{
					ans+=0ll+cnt2;
				}
			}else{
				int j=i+1,cnt2=0;
				while(j<=n/2+((n%2==1)?1:0)&&v1[i].a!=v2[i].a){
					if(v2[i].a+v2[j].a>v1[i].a){
						v2[j].a-=(v1[i].a-v2[i].a);
						cnt2+=(v1[i].a-v2[i].a);
						if(v2[j].c==v2[i].c){
							cnt2-=(v1[i].a-v2[i].a);
						}
						v2[i].a=v1[i].a;
					}else{
						v2[i].a+=v2[j].a;
						cnt2+=v2[j].a;
						if(v2[j].c==v2[i].c){
							cnt2-=v2[j].a;
						}
						v2[j].a=0;
					}
					j++;
				}
				if(v1[i].a!=v2[i].a){
					ans+=0ll+cnt2;
					break;
				}else{
					ans+=0ll+cnt2;
				}
			}
		}else{
			ans+=0ll+min(v1[i].a,v2[i].a);
			if(v1[i].a<v2[i].a){
				int j=i+1,cnt2=0;
				while(j<=n/2+((n%2==1)?1:0)&&v1[i].a!=v2[i].a){
					if(v1[i].a+v1[j].a>v2[i].a){
						v1[j].a-=(v2[i].a-v1[i].a);
						cnt2+=(v2[i].a-v1[i].a);
						if(v1[j].c==v2[i].c){
							cnt2-=(v2[i].a-v1[i].a);
						}
						v1[i].a=v2[i].a;
					}else{
						v1[i].a+=v1[j].a;
						cnt2+=v1[j].a;
						if(v1[j].c==v2[i].c){
							cnt2-=v1[j].a;
						}
						v1[j].a=0;
					}
					j++;
				}
				if(v1[i].a!=v2[i].a){
					ans+=0ll+cnt2;
					break;
				}else{
					ans+=0ll+cnt2;
				}
			}else{
				int j=i+1,cnt2=0;
				while(j<=n/2+((n%2==1)?1:0)&&v1[i].a!=v2[i].a){
					if(v2[i].a+v2[j].a>v1[i].a){
						v2[j].a-=(v1[i].a-v2[i].a);
						cnt2+=(v1[i].a-v2[i].a);
						if(v2[j].c==v1[i].c){
							cnt2-=(v1[i].a-v2[i].a);
						}
						v2[i].a=v1[i].a;
					}else{
						v2[i].a+=v2[j].a;
						cnt2+=v2[j].a;
						if(v2[j].c==v1[i].c){
							cnt2-=v1[j].a;
						}
						v2[j].a=0;
					}
					j++;
				}
				if(v1[i].a!=v2[i].a){
					ans+=0ll+cnt2;
					break;
				}else{
					ans+=0ll+cnt2;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//2 a 2 a
//1 b 1 b
//2 a 2 a
//
//
//1 c 5 b
//2 c 2 c
//5 b 1 c
//bccbbbb
//bbbbbbb
//cccbbbbb