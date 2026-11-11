/* * CSP - J 2026 Task 2 string.cpp
 *   Why is it so hard?
 *   Just 60 points.
 */

#include<stdio.h>

int n;
char string[(int)1e8+5];
int pointer=1;

int main(){
	#ifndef STDIO
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for(int j=pointer;j<=pointer+a-1;j++){
			string[j]=c;
		}
		pointer+=a;
	}
	pointer--;
	int mid=pointer/2;
	int l,r;
	if(pointer%2==1){
		l=mid,r=mid+2;
	}
	else{
		l=mid,r=mid+1;
	}
	int ans=0;
	for(;l>=1 && string[r]!='\0';l--,r++){
		if(string[l]!=string[r]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
