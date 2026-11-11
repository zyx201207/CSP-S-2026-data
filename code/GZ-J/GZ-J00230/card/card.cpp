// Gz-J00230 黔西市思源实验学校 许邴淳
#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m,sum;
	cin>>m>>n;
	int a[m];
	int num=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(i==m-1){
			sum=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
		if(a[j]==i){
			num++;
		}
	}
	if(a[i]==sum){
		cout<<m<<" ";
	}else{
		cout<<num<<" ";
	}
	num=0;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
