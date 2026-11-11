 #include <bits/stdc++.h>
 using namespace std;
 char a[6],b[6],c[6],d[6],ans[5];
 int main ( ){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	memset(ans,'0',sizeof(ans));
 	scanf("%s",a+1);
 	scanf("%s",b+1);
 	scanf("%s",c+1);
 	scanf("%s",d+1);
 	if (a[1]==c[1]&&a[2]==c[2]){
 		ans[1]='1';
 		if (b[1]==d[1]&&b[2]==d[2]){
 			ans[2]='1';
 			if (b[3]<'D'&&d[3]<'D'||b[3]>'D'&&d[3]>'D'){
 				ans[3]='1';
 				if (b[3]+1==d[3]||d[3]+1==b[3]){
 					ans[4]='1';
				 }
			 }
		 }
	 }
	for (int i=1;i<=4;i++){
		cout <<ans[i];
	}
 }
