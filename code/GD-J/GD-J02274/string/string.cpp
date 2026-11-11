#include<bits/stdc++.h>
using namespace std;
struct hui{
	long long a=0;
	char c;
};
hui str[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	cin>>n;
	int l=0,r=n-1;
	cout<<l<<" "<<r<<endl;
	for(int i=0;i<n;i++){
		cin>>str[i].a>>str[i].c;
	}
	
	for(;l!=r&&l<r;){
//		cout<<"1"<<endl; 
		if(str[l].c != str[r].c){//需要修改 
			if(str[l].a == str[r].a){//全部改完 
				ans+=str[l].a;
//				cout<<str[r].c<<str[r].a<<" "<<ans<<endl;
				l++;
				r--;
				continue;			
			}
			if(str[l].a < str[r].a){//把左换掉 
				ans+=str[l].a;
//cout<<str[l].c<<str[l].a<<" "<<ans<<endl;
				str[r].a-=str[l].a;
				l++;
				continue;
			}
			if(str[l].a > str[r].a){//把右换掉 
				ans+=str[r].a;
//cout<<str[r].c<<str[r].a<<" "<<ans<<endl;
				str[l].a-=str[r].a;
				r--;
				continue; 
			}
		}
		else{//继续看 
			if(str[l].a == str[r].a){//全部改完 
				l++;
				r--;
				continue;			
			}
			if(str[l].a < str[r].a){//把左换掉 
				str[r].a-=str[l].a;
				l++;
				continue;
			}
			if(str[l].a > str[r].a){//把右换掉 
				str[l].a-=str[r].a;
				r--;
				continue; 
			}
		}
	}
	cout<<ans;
	return 0;
} 
