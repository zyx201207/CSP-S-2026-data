#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> wait(n);
	//0¥˝—°£¨-1Ã‘Ã≠£¨1»∑∂® 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=0;j--){
		int count=0;
		for(int i=0;i<n;i++){
			if(wait[i]==-1||wait[i]==1){
				continue;
			}
			if(((a[i]>>j)&1)==1){
				count++;
			}
		}
		if(count>m){
//			cout<<"now is"<<j<<endl;
			for(int i=0;i<n;i++){
				if(wait[i]==-1||wait[i]==1){
					continue;
				}
				if(((a[i]>>j)&1)==0){
					wait[i]=-1;
//					cout<<j<<endl;
//					cout<<i<<" "<<-1<<endl;
				}
			}
			
		}
		else if(count==m){
			for(int i=0;i<n;i++){
				if(wait[i]==-1||wait[i]==1){
					continue;
				}
				if(((a[i]>>j)&1)==1){
					wait[i]=1;
//					cout<<j<<endl;
//					cout<<i<<" "<<1<<endl;
				}
			}
			m=0;
			break;
		}
		else{
			for(int i=0;i<n;i++){
				if(wait[i]==-1||wait[i]==1){
					continue;
				}
				if(((a[i]>>j)&1)==1){
					wait[i]=1;
//					cout<<j<<endl;
//					cout<<i<<" "<<1<<endl;
					m--;
				}
			}
		}
	}
	int ans=(1<<31)-1;
//	for(int i=0;i<n;i++){
//		cout<<wait[i]<<" ";
//	}cout<<endl;
	for(int i=0;i<n;i++){
		if(wait[i]==1){
			ans&=a[i];
		}
	}
	int i=0;
	while(m){
		if(wait[i]==0){
			ans&=a[i];
			m--;
		}
		i++;
	}
	cout<<ans;
//	cout<<((3>>3)&1);
	return 0;
}
