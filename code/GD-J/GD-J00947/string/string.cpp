#include <bits/stdc++.h>
using namespace std;
int a[2*100000+3],v[2*100000+3];
char c[2*100000+3];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t=0;
    scanf("%lld",&n);
    string s="";
    bool f=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[i]=v[i-1]+a[i];;
        cin >> c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=2;i<=n;i++){
    	if(c[i]!=c[i-1]){
    		f=false;
    		break;
		}
	}
	if(f){
		printf("%d",0);
		return 0;
	}
	t=v[n];
    string s1="";
    for(int i=t-1;i>=0;i--){
    	s1[t-1-i]=s[i];
	}
    long long cnt=0;
    if(t&1==0){
        for(int i=0;i<=t/2;i++){
            if(s[i]!=s1[i]){
                cnt++;
            }
        }
    }else{
        for(int i=0;i<t/2+1;i++){
            if(s[i]!=s1[i]){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
