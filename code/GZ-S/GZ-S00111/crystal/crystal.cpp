//GZ-S00111 遵义二中 包浡言 
#include <bits/stdc++.h>
using namespace std;

int main(){
   int n=0;
   int m=0;
   int js=0;
   cin>>n;
   cin>>m;
   int a1[n];
   int a[n];
   int mi=0;
   
 
   int ass=1;
   int kong=0;
   
   for(int i=1;i<=n;i++){
   	cin>>a1[i];
   }
   mi=a1[1];
   
   for(int q4=1;q4<=n;q4++){     //sort() 
   		mi=min(mi,a1[q4]);
   	}
   while(1){
    	for(int q5=1;q5<=n;q5++){    
    		if(a1[q5]==mi){      
    		  a[ass]=a1[q5];
			  ass++;	
			}
		
		}
		mi++;
		if(ass==n+1){
			break;
		}
	
	}
/*
   for(int q4=1;q4<=n;q4++){
   	cout<<a[q4]<<endl;
   }
   cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5];     //测试 


   
}
*/
  

   int bz=2;
   for(int q1=1;q1<n;q1++){         //主 
     while(1){
	   	if(a[q1]==a[q1+1]){
	   		bz++;
	   		break;
		}else{
			for(int q2=1;q2<bz;q2++){
				if(m>0){
					m--;
				    a[q2]++;						
		}
	}
}
        if(m==0){
		  break;
		  q1=n-1;
			}
}
}
/*
    for(int q4=1;q4<=n;q4++){
    	cout<<a[q4]<<" ";
	}

*/
    for(int q3=2;q3<=n;q3++){
    	if(a[q3]==a[q3-1]){
    		kong=a[q3];    //输出 
		}
		if(a[q3]==kong){
			js++;
		}
}
	
	cout<<js+1;
}

