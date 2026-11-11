#include<bits/stdc++.h>
using namespace std;
long long n,a,j,l,sum,o,y;
char c,s;
string t;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cin>>a>>c;
		cout<<0;
		return 0;
	}
	if(n==2){
		int q,e;
		char w,r;
		cin>>q>>w>>e>>r;
		if(min(q,e)%2==1){
			cout<<min(q,e)/2+1;
		}else{
			cout<<min(q,e)/2;
		}
		return 0;
	}
	j=1;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int h=1;h<=a;h++){
			t[j]=c;
			j++;
		}
		if(a%2==1){
			s=c;
			l=1;
		}
	}
	if(l==1){
		if(s!=t[t.size()/2+1]){
			sum=1;
			for(int i=1;i<=t.size();i++){
				if(t[i]==s&&t[t.size()-i+1]==t[t.size()/2+1]){
					t[i]=t[t.size()/2+1];
					t[t.size()/2+1]=s;
					y=1;
					break;
				}
				if(t[i]==t[t.size()/2+1]&&t[t.size()-i+1]==s){
					t[t.size()-i+1]=t[t.size()/2+1];
					t[t.size()/2+1]=s;
					y=1;
					break;
				}
			}
			if(y==0){
				for(int i=1;i<=t.size();i++){
					if(t[i]==s){
						t[i]=t[t.size()/2+1];
						t[t.size()/2+1]=s;
						y=1;
						break;
					}
					if(t[t.size()-i+1]==s){
						t[t.size()-i+1]=t[t.size()/2+1];
						t[t.size()/2+1]=s;
						y=1;
						break;
					}
				}
			}
		}
	}
	for(int j=1;j<=t.size()/2;j++){
		if(t[j]!=t[t.size()-j+1]){
			y=0;
			sum++;
			s=t[j];
			char r=t[t.size()-j+1];
			for(int i=1;i<=t.size();i++){
				if(t[i]==s&&t[t.size()-i+1]==r&&t[i]!=t[t.size()-i+1]){
					t[i]=r;
					r=s;
					y=1;
					break;
				}
				if(t[i]==r&&t[t.size()-i+1]==s&&t[i]!=t[t.size()-i+1]){
					t[t.size()-i+1]=r;
					r=s;
					y=1;
					break;
				}
			}
			if(y==0){
				for(int i=1;i<=t.size();i++&&t[i]!=t[t.size()-i+1]){
					if(t[i]==s){
						t[i]=r;
						r=s;
						y=1;
						break;
					}
					if(t[t.size()-i+1]==s&&t[i]!=t[t.size()-i+1]){
						t[t.size()-i+1]=r;
						r=s;
						y=1;
						break;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
