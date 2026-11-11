#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	
	long long shu,cishu,shuchu=0,temp=0,cishulj=0;
	cin>>shu>>cishu;
	long long al[shu+1];
	
	for (int i=1;i<=shu;i++){
		cin>>al[i];
	}
	
	sort(al+1,al+shu+1);
	
	for (int i=1;i<=shu;i++){
		for (int j=1;j<=i;j++){
			cishulj+=al[i]-al[j];
			temp++;
			if (cishulj>cishu){
				temp--;
			}
		}
		
		if (temp>shuchu){
			shuchu=temp;
		}
		temp=0;
		cishulj=0;
	}
	
	cout<<shuchu;
	freopen("crystal.out","w",stdout);
	return 0; 
}
