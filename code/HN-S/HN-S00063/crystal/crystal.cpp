#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;
	
	cin>>n>>m;
	long long aa[130000];
	
	long long bb[125000];

	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
	cout<< endl;
	sort(aa,aa+n);

/*	for(int i=0;i<n;i++){
		cout<<aa[i]<<' ';}*/
		
	for(int i=1;i<n;i++){
		
		bb[i] =aa[i] -aa[i-1] ;
	//	cout<<bb[i]<<' ';
	}
	
	int front=0,place,cc;
	for(int i=1;i<n;i++){
		//int i;
		//	cout<<"{";
		place=i-1;
		int num = 0;
		while(num<m){
		//	cout<<"<";
		
			for(int j=i;j>=place;j--){
				num += bb[j];
				//cout<< num<<" ";
				
			}
		//	cout<<">";
			place--;
			cc++;
		};
		//cout<<cc<<endl;
		if(cc>front)front=cc;
		//	cout<<"}"<<endl;
	}
	//ÌâÄ¿nb666 
	cout<<front;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
