#include<bits/stdc++.h>
using namespace std;
int a[222222];
string t[222222];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,b=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
		int b=a[i];
		string s;
		while(b>0){
			s=char((b%2)+48)+s;
			b/=2;//cout<<s<<' ';
			t[i]=s;//cout<<t[i]<<' ';
		}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int k1=t[i].size(),k2=t[j].size();
			string b1;
			for(int k=0;k<min(k1,k2);k++){//cout<<'a';
				if(t[i][k1-k]=='1' and t[j][k2-k]=='1'){
					b1='1'+b1;
				}
				else{cout<<t[i][k1-k]<<' '<<t[j][k2-k]<<' ';
				    b1='0'+b1;
				}
			}cout<<b1;
			int a=0,p=1;
			for(int k=b1.size()-1;k>0;k--){//cout<<k;
				if(b1[k]=='1'){//cout<<'a';
					a+=p;//cout<<a<<p<<' ';
				}
				p*=2;
			}//cout<<a;
			cout<<endl;
			b=max(a,b);//cout<<'a'<<a;if(a>b){b=a;}
		}
	}	
	}
	cout<<b;
    return 0;
}
