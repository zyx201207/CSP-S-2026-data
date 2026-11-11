///小X和小R能不能去死啊！！！
#include<bits/stdc++.h>
using namespace std;
int n,t,cnt,a;
char c,s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a,&c);
		for(int j=1;j<=a;j++){
			s[++t]=c;
//			cout<<t<<' '<<s[t]<<endl;
		}
    }
//    cout<<"t="<<t<<endl;
	int mmid=t/2;//中位下标前取
//	cout<<"mid="<<mmid<<endl;
	for(int p=mmid;p>=1;p--){
//        printf("s[p=%d]=%c,s[t-p+1=%d]=%c",p,s[p],t-p+1,s[t-p+1]);
//        cout<<s[p]<<'\n';
		if(s[p]!=s[t-p+1]){
//            cout<<"!!!";
            cnt++;
		}
//        cout<<endl;
	}
	cout/*<<"cnt="*/<<cnt;
    fclose(stdin),fclose(stdout);
    return 0;
}
///求AC！！！求AC！！！求AC！！！
///求AC！！！求AC！！！求AC！！！
///求AC！！！求AC！！！求AC！！！
