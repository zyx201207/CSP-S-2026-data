#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,m,m_a,i_a,number,max_number=0;
	cin>>n>>m;
	int a[500000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<n;i++){
		number=0;
		m_a=m;
		i_a=i;
		while(i_a>=1&&m_a>0){
			if(a[i]-a[i_a]<=m_a){
				number++;
				m_a=m_a-a[i]+a[i_a];
				i_a--;
			}
			else{
				i_a=-1;
				m_a=-1;
			}
		}
		if(max_number<number){
			max_number=number;
		}
	}
	cout<<max_number;
	return 0;
}
