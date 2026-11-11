#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+5;
int a[M],num;
char c[M];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
	}
	string str="";
    int len=s.size();
    for(int i=len;i>=0;i--){
        str+=s[i];
    }
    int sum=0,ans=0;
	cout<<str<<" "<<s<<endl;
	for(int i=0;i<=len;i++){
        if(s[i]==str[i]){
            sum++;
        }else{
            ans++;
        }
	}
	if(sum==len){
        cout<<0;
	}else{
        cout<<ans;
	}
	return 0;
}
