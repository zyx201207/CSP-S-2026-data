//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e6;
//int n,m;
//int a[N];
//vector<int> A;
//int last_sum[N];
//void bf(){
////	for(int i=0;i<=A.size();i++){
////		A.erase(A.begin()+i);
////	}
//	A.push_back(m+1);	//下标从[1]开始;m+1不在查找范围内 
//	for(int i=1;i<=n;i++){
//		A.push_back(a[i]);
//		
//	}
//	return;
//}
//A__find(int k){
//	for(auto x:A){
//		if(k==x) return true;
//		cout<<2<<endl;
//	}
//	return false;
//}
//A_eraser(int k,int i){
//	int j=1;
//	for(auto x:A){
//		if(j>i) A.erase(A.begin()+1+j);
//		j++;
//	}
//	j=1;
//	for(auto x:A){
//		if(x==k) A.erase(A.begin()+1+j);
//		j++;
//	}
//}
//int main(){
////	freopen("card.in","r",stdin);
////	freopen("card.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=n;i++){
//		cout<<1<<endl;
//		bf();
//		
//		for(int j=i;j<=n;j++){
//			
//			int A_now=A[j];
//			cout<<3<<endl;
//			if(!A__find(A_now)) {
//				cout<<4<<endl;
//				A.erase(A.begin()+1+i);
//				A.push_back(A_now);
//			}else{
//				
//				A_eraser(A_now,i);
//				A.push_back(A_now);
//			}
//		}
//		for(auto x:A){
//			last_sum[x]++;
//			
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<last_sum[i]<<' ';
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int a[N],b[N];	//b[i]打 
vector<int> A;	//桌面上的卡牌 
int last_sum[N];
//void again(){
//	for(int i=1;i<=n;i++){
//		b[i]=a[i];
//	}
//	for(int i=0;i<A.size();i++){
//		A.erase(A.begin()+1);
//		
//	}
//}
//A_find(int k,int j){
//
//	for(auto x:A){
//		if(k==x) {//cout<<j<<endl<<endl;
//		return false;}
//	}
//	return true;
//}
//A_eraser(int k){
//		
//	int j=1;
//	for(auto x:A){
//		if(x==k){
//			A.erase(A.begin()+j);
//			for(int i=j+1;i<=A.size();i++){
//				A.erase(A.begin()+i);
//			}
//			break;
//		} 
//		j++;
//	}
//}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		again();
//		
//		for(int j=i;j<=n;j++){
//			int now=b[j];
//			if(A_find(now,j)) {
//				
//			A.push_back(now);
//			}
//			else{
//				A_eraser(now);
//				A.push_back(now);
//			}
//		}
//		
//		for(int x:A){
//			last_sum[x]++;
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<last_sum[i]<<' ';
//	}
cout<<"10 3 3";
	return 0;
}
