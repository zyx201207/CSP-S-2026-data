#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[9999];
    char c[9999];
    string s;    
	string f;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        int t=a[i];
        while(t--){
            s+=c[i];
        }
    }
	for(int i=n;i>=1;i--){
	
        while(a[i]--){
            f+=c[i];
        }
    }
    for(int i=0;i<s.size();i++){
//    	cout<<s[i]<<endl<<f[i]<<endl;
    	if(s[i]!=f[i]){
    		cout<<2;
    		return 0;
		}
	}
	cout<<0;
    fclose(stdin);
    fclose(stdout);

}

