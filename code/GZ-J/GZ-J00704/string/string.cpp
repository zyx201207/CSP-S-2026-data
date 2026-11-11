//GZ-J00704 遵义市新蒲中学 谢俊星
#include <bits/stdc++.h>
using namespace std;
struct ab{
	int a;
	char b;
}A[20005],B[20005];

int main(){
	/*freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);*/
	string s="";
	int n,a[2]={0},s1=0,k=0;
	char cc;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>A[i].a>>A[i].b;
		B[n-1-i].a=A[i].a;
		B[n-1-i].b=A[i].b;
		s1+=A[i].a;
	}
	int i=0;
	while(i<s1/2){
		if(A[a[0]].a==0){
			a[0]++;
		}
		if(B[a[1]].a==0){
			a[1]--;
		}
		if(A[a[0]].b!=B[a[1]].b){
			k++;
		}
		A[a[0]].a--;
		B[a[1]].a--;
		
		i++;
		
	}
	cout<<k;
	return 0;
}


