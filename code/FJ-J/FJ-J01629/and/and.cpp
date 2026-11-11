#include<iostream>
#include<cstring>
using namespace std;
int ma(int x){
	int y=1;
	int xy=0;
	while(x>0){
		xy+=x%2*y;
		x=x/2;
		y=y*10;
	}
	return xy;
}
int maa(int x2){
	int xy2=0;
	while(x2>0){
		if(x2%2==1){
			xy2++;
		}
		x2=x2/2;
	}
	return xy2;
}
int na(int x1,int y1){
	int xy1=0;
	int z=1;
	while(x1>0&&y1>0){
		if(x1%10==y1%10){
			xy1+=x1%10*z;
		}
		x1=x1/10;
		y1=y1/10;
		z*=10;
	}
	return xy1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int a[20000][3];
	for(int i=0;i<n;i++){
		cin>>a[i][0];
		a[i][1]=ma(a[i][0]);
		a[i][2]=maa(a[i][1]);
	}
	int max_num=0,max_w=0,max_number=0;
	for(int i=0;i<m;i++){
		max_num=0;
		for(int j=0;j<n;j++){
			if(a[j][2]>max_num){
				max_num=a[j][2];
				max_w=j;
			}
			else if (a[j][2]==max_num&&a[j][0]>a[max_w][0]){
				max_w=j;
			}
		}
		if(i==1){
			max_number+=a[max_w][1];
		}
		else{
			max_number=na(max_number,a[max_w][1]);
		}
		a[max_w][1]=0;
		a[max_w][0]=0;
		a[max_w][2]=0;
	}
	int aaa=1;
	int maxaa=0;
	while(max_number>0){
		maxaa+=max_number%10*aaa;
		max_number=max_number/10;
		aaa*=2;
	}
	cout<<maxaa;
	return 0;
}
