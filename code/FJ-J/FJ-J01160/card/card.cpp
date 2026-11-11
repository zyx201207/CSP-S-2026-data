#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010]={},sum[100010]={};
int ande(int x,int sum){
	if(a[sum]>x){
		return sum-1;
	}
	return ande(x,sum+1);
}
int mian(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		sum[i]+=ande(i,1);
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0; 
}
//c:\program files (x86)\dev-cpp\mingw64\x86_64-w64-mingw32\bin\ld.exe	C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o): in function `main':
//18		R:\winlibs64-9.3.0-7.0.0\_TMP_\mingw-w64-v7.0.0\mingw-w64-crt\crt\crt0_c.c	undefined reference to `WinMain'
//E:\FJ-J01160\card\collect2.exe	[Error] ld returned 1 exit status
// ÉñÃØ±àÒë£¬ÎÑºÞÄã£¬ßÀßÀ¶ö°¡°¡£¨ÒûºÞ¶«ÄÏ£© 
//±àÒëºÃÒõÏÕ£¬£¨ÒõÏÕµÄÐ¦ÈÝ.mp2) 
