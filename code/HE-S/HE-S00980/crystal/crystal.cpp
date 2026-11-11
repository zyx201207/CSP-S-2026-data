#incude
int main(){
	int n = input();
	int m = input();
    int a = input();
    int b = input();
    int c = input();
    int d = input();
    int e = input();
    int v = 1;
	for(j >= 1,j <= m,j--){
		if(a + 1 == b || a + 1 == c || a + 1 == d || a + 1 == e){
           int v += 1;
           int a += 1;
           int m -= 1;
           if(m == 0){
           	  break
		   }
	}
	    if(b + 1 == c || b + 1 == d || d + 1 == e || b + 1 == a){
           int v += 1;
           int b += 1;
           	  break
		   }
           int m -= 1;
           if(m == 0){
	}
	    if(c + 1 == b || c + 1 == a || c + 1 == d || c + 1 == e){
           int v += 1;
           int c += 1;
           int m -= 1;
           if(m == 0){
           	  break
		   }
	}
		if(d + 1 == b || d + 1 == c || d + 1 == a || d + 1 == e){
           int v += 1;
           int d += 1;
           int m -= 1;
           if(m == 0){
           	  break
		   }
	}
		if(e + 1 == b || e + 1 == c || e + 1 == d || e + 1 == a){
           int v += 1;
           int e += 1;
           int m -= 1;
           if(m == 0){
           	  break
		   }
	}
    printf(v,"%d");
}	
    return 0;
}
