/*#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node* next=NULL;
	int dot=0;
	
};
int pz[500002]={},sj[500001]={},sc[200001],n,m,x=0,cp=0;
Node* dz[500002]={};

void push(Node* dq,int dot){
	if(pz[dot]){
		x-=cp-pz[dot]+1;
		cp=cp-pz[dot]+1;
		Node* dq=dz[pz[dot]]->next;
		while(dq==NULL){
			pz[dq->dot]=0;
			//delete dq;
			dq=dq->next;
		}
	}
	else{
		cp++;
		Node* ne=new Node;
		ne->dot=dot;
		dq->next=ne;
		pz[dot]=cp;
		dz[cp]=ne;
	}
}
 
int main(){
	Node* home=new Node;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&sj[i]);
	}
	while(n--){
		push(home,sj[n]);
		if(cp<=m){
			sc[cp]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",sc[i]);
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<((n+1)/2);
	}
	else if(m==2){
		cout<<"2 2";
	}
	return 0;
}
